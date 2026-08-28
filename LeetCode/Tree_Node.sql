// Problem Link: https://leetcode.com/problems/tree-node/

SELECT id,
       CASE 
           WHEN p_id IS NULL THEN 'Root'
           WHEN EXISTS (SELECT 1 FROM Tree sub WHERE sub.p_id = Tree.id) THEN 'Inner'
           ELSE 'Leaf'
       END AS type
FROM Tree;
