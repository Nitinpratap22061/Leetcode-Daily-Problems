-- Last updated: 10/5/2025, 9:00:39 AM
# Write your MySQL query statement below
SELECT MAX(salary) AS secondhighestsalary
FROM employee
WHERE salary < (SELECT MAX(salary) FROM employee);
