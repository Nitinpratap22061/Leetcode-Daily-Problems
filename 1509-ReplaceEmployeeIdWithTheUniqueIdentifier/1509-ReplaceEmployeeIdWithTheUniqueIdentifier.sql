-- Last updated: 10/5/2025, 8:55:26 AM
# Write your MySQL query statement below
# Write your MySQL query statement below
SELECT
EmployeeUNI.unique_id, Employees.name
FROM Employees
LEFT JOIN EmployeeUNI on Employees.id = EmployeeUNI.id
