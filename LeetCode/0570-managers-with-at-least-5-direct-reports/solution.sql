SELECT M.name as name 
FROM Employee M JOIN Employee E
ON M.id = E.managerId 
GROUP BY M.id
HAVING COUNT(E.id) >= 5
