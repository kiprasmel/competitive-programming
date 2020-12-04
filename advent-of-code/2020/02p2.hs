import Data.List.Split (divvy)
import Data.Bits

matchesCount :: Int -> Int -> Char -> String -> Bool
matchesCount minn maxx c s = (
                              xor
                              (minn < length s && s !! minn == c)
                              (maxx < length s && s !! maxx == c))

solveOne :: String -> Bool
solveOne line = matchesCount mi ma c s
  where
    xs  = words line
    mi = (read (xs !! 0) :: Int) - 1
    ma = (read (xs !! 1) :: Int) - 1
    c  = head $ xs !! 2
    s  =        xs !! 3

solveV :: [String] -> Bool
solveV xs = matchesCount mi ma c s
  where
    mi = (read (xs !! 0) :: Int) - 1
    ma = (read (xs !! 1) :: Int) - 1
    c  = head $ xs !! 2
    s  =        xs !! 3

main :: IO ()
-- main = interact $ show . length . filter (== True) . map solveOne . lines
-- main = interact $ show . length . filter (== True) . map solveV . map words . lines
main = interact $ show . length . filter (== True) . map solveV . divvy 4 4 . words

