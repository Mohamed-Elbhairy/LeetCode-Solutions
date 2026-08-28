// Problem Link: https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/

# Write your MySQL query statement below
SELECT unique_id , name  
FROM Employees E LEFT JOIN EmployeeUNI EI 
    ON E.id = EI.id
