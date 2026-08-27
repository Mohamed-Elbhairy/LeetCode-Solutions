SELECT D.name AS Department ,
     E.name AS Employee ,
     E.Salary AS Salary
FROM Employee E RIGHT JOIN Department D
ON E.departmentId = D.id
WHERE E.Salary = (SELECT MAX(E1.Salary) FROM Department D1 INNER JOIN Employee E1 ON E1.departmentId = D1.id WHERE D.id = D1.id )


