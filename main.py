from flask import *
import sqlite3

app = Flask(__name__)

@app.route('/')
def index():
    conn = sqlite3.connect('magnet.db')
    cur = conn.execute("SELECT * FROM door WHERE id=1")
    row =cur.fetchone()
    if int(row[1])==1:
        msg="Water Tank is full, Turn off the Motor"
    else:
        msg="Normal!"
    return render_template('home.html',row=row,msg= msg)

@app.route('/add/<d>')
def add_data(d):
    conn= sqlite3.connect("magnet.db")
    conn.execute("UPDATE door SET level=? WHERE id=?",(d,1))
    conn.commit()
    cur = conn.execute("SELECT * FROM door WHERE id=1")
    row = cur.fetchone()

    return str(row[2])

@app.route('/s1/<a>')
def s1(a):
    conn = sqlite3.connect("magnet.db")
    conn.execute("UPDATE door SET s1=? WHERE id=?",(a,1))
    conn.commit()
    if a=='1':
        msg1 ="Motor is On"
    else:
        msg1 = "Motor is Off"
    cur=conn.execute("SELECT * FROM door WHERE id=1")
    row=cur.fetchone()
    if int(row[1]) == 1:
        msg = "Water Tank is full, Turn off the Motor"
    else:
        msg = "Normal!"
    return render_template("home.html",msg1=msg1,row=row,msg=msg)
if __name__ == "__main__":
    app.run(host="0.0.0.0")
