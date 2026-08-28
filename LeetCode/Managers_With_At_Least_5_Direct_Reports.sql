// Problem Link: https://leetcode.com/problems/managers-with-at-least-5-direct-reports/

SELECT M.name as name 
FROM Employee M JOIN Employee E
ON M.id = E.managerId 
GROUP BY M.id
HAVING COUNT(E.id) >= 5
