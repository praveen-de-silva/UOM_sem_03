-- ===========
-- DB setting
-- ===========

-- Connect from CMD
psql -U postgres -d database_name

-- Show all databases
\l

-- Connect to a database
\c database_name

-- Create a new database
CREATE DATABASE db_name;

-- Delete a database
DROP DATABASE db_name;

-- ================
-- Table Commands
-- ================

-- Show all tables
\dt

-- Create a table
CREATE TABLE table_name (
  id SERIAL PRIMARY KEY,
  name TEXT,
  age INT
);

-- View table structure
\d table_name

-- Delete a table
DROP TABLE table_name;

-- Rename a table
ALTER TABLE old_name RENAME TO new_name;

-- ==============
-- Data Commands
-- ==============

-- Insert data
INSERT INTO table_name (name, age)
VALUES ('Alice', 22);

-- View data
SELECT * FROM table_name;

-- Filter data
SELECT * FROM table_name WHERE age > 20;

-- Update data
UPDATE table_name
SET age = 25
WHERE name = 'Alice';

-- Delete rows
DELETE FROM table_name WHERE age < 18;

-- =================
-- Query Essentials
-- =================

-- Sort data
SELECT * FROM table_name ORDER BY age DESC;

-- Limit rows
SELECT * FROM table_name LIMIT 5;

-- Count rows
SELECT COUNT(*) FROM table_name;

-- Distinct values
SELECT DISTINCT age FROM table_name;

-- Combine conditions
SELECT * FROM table_name WHERE age > 20 AND name = 'Alice';

-- ======
-- Joins
-- ======

-- Inner Join
SELECT *
FROM students s
JOIN courses c ON s.course_id = c.id;

-- Left Join
SELECT *
FROM students s
LEFT JOIN courses c ON s.course_id = c.id;




-- Inner Join
SELECT *
FROM students s
JOIN courses c ON s.course_id = c.id;

-- Left Join
SELECT *
FROM students s
LEFT JOIN courses c ON s.course_id = c.id;

-- ===========
-- Aggregates
-- ===========

SELECT AVG(age), MAX(age), MIN(age)
FROM table_name;

-- ======================
-- Useful psql Shortcuts
-- ======================

\q          -- quit
\?          -- help
\dt         -- list tables
\d table    -- describe table
\du         -- list users

