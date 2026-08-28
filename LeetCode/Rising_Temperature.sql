// Problem Link: https://leetcode.com/problems/rising-temperature/

SELECT W.id 
FROM Weather W 
JOIN Weather W1
    ON W.recordDate = DATE_ADD(W1.recordDate, INTERVAL 1 DAY)
WHERE W.temperature > W1.temperature;
