# Write your MySQL query statement below
SELECT Employees.name, EmployeeUNI.unique_id
From Employees
LEFT JOIN EmployeeUNI ON Employees.id = EmployeeUNI.id;

