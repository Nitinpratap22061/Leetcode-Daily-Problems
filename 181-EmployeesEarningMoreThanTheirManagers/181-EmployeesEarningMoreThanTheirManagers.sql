-- Last updated: 10/5/2025, 9:00:38 AM
SELECT e1.name AS Employee
FROM Employee e1
JOIN Employee e2
  ON e1.managerId = e2.id
WHERE e1.salary > e2.salary;
