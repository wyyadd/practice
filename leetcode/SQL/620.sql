SELECT * FROM Cinema c WHERE c.id & 1 = 1 AND c.description <> "boring" ORDER BY c.rating DESC;
