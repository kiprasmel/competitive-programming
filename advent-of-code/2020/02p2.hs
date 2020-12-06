import Data.Bits (xor)

matchesCount :: Int -> Int -> Char -> String -> Bool
matchesCount minn maxx c s = xor
                            	(minn < length s && s !! minn == c)
                              	(maxx < length s && s !! maxx == c)

solveOne :: [String] -> Bool
solveOne xs = matchesCount mi ma c s
  where
    mi = (read (xs !! 0) :: Int) - 1
    ma = (read (xs !! 1) :: Int) - 1
    c  = head  (xs !! 2)
    s  =       (xs !! 3)

main :: IO ()
main = interact $ show . length . filter (== True) . map (solveOne . words) . lines
