import cs50
import csv
import os

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Defines file name
file_name = "survey.csv"

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")


@app.route("/form", methods=["POST"])
def post_form():

    # retrieves form info
    name = request.form.get("name")
    mail = request.form.get("mail")
    number = request.form.get("phone")
    cont = request.form.get("continentSelect")
    movie = request.form.get("movie")
    food = request.form['food']

    # inputs form values into list
    values = [name, mail, number, cont, movie, food]

    # iterates through list to check if any value is invalid
    for i in values:
        if i.strip() == "":
            return render_template("error.html", message="empty fields")

    # inserts values into csv file
    with open(file_name, mode='a') as file:
        inputs = csv.writer(file, delimiter=',')
        inputs.writerow((values))

    return redirect("./sheet", code="302")


@app.route("/sheets")
def get_sheet():

    # checks if survey file exists
    if os.path.isfile(file_name) is not True:
        return render_template("error.html", message="There are no submissions")

    # prepares list
    a = []

    # opens file and inserts it to my list
    with open(file_name, mode='r') as file:
        submissions = csv.reader(file)
        for row in submissions:
            a.append(row)

    # returns submission list
    return jsonify(a)


@app.route("/sheet")
def load_sheets():
    return render_template("sheet.html")