# Write your MySQL query statement below
SELECT unique_id , name  
FROM Employees E LEFT JOIN EmployeeUNI EI 
    ON E.id = EI.id
