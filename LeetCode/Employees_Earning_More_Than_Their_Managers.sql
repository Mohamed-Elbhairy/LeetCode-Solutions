// Problem Link: https://leetcode.com/problems/employees-earning-more-than-their-managers/

# Write your MySQL query statement below
SELECT E.name As Employee 
FROM Employee E  JOIN Employee M
    ON E.managerId  = M.id 
        WHERE E.Salary > M.Salary
