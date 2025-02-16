import sqlite3
conn = sqlite3.connect('magnet.db')
#conn.execute("CREATE TABLE door(id INTEGER PRIMARY KEY AUTOINCREMENT,level TEXT,s1 TEXT)")
conn.execute("INSERT INTO door(level,s1) VALUES(5,1)")
conn.commit()
cur = conn.execute("SELECT * FROM door")
print(cur.fetchone())
