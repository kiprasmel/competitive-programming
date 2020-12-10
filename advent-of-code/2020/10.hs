import Data.List       (sort)
import Data.List.Split (divvy)

wrap :: [Int] -> [Int]
wrap sortedXs = [0] ++ sortedXs ++ [last sortedXs + 3]

diff :: [Int] -> Int
diff (a:b:_) = b - a

count :: Int -> [Int] -> Int
count n = length . filter (== n)

countDiffs :: [Int] -> Int
countDiffs xs = count 1 xs * count 3 xs

main :: IO ()
main = interact $ (++ "\n") . show . countDiffs . map diff . divvy 2 1 . wrap . sort . map read . lines
