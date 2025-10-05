-- Last updated: 10/5/2025, 9:00:40 AM
# Write your MySQL query statement below

Select  firstName, lastName, city,state
FROM PERSON p
LEFT JOIN  ADDRESS A ON p.personId = a.personId