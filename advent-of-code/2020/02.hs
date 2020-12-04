matchesCount :: Int -> Int -> Char -> String -> Bool
matchesCount minn maxx c s = len >= minn && len <= maxx
  where
    len = length $ filter (c ==) s

solveOne :: String -> Bool
solveOne line = matchesCount mi ma c s
  where
    w  = words line
    mi = read (w !! 0) :: Int
    ma = read (w !! 1) :: Int
    c  = head $ w !! 2
    s  = w !! 3

main :: IO ()
main = interact $ show . length . filter (== True) . map solveOne . lines

