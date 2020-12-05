binarySearch :: String -> Int -> Int -> Int -> Char -> Char -> Int
binarySearch row rowIdx from to lt gte
  | from == to  = to
  | char == lt  = binarySearch row (rowIdx + 1) (from   ) (mid) lt gte
  | char == gte = binarySearch row (rowIdx + 1) (mid + 1) (to ) lt gte
  where
    char = row !! rowIdx
    mid  = (from + to) `div` 2

calcSeatId :: (String, String)-> Int
calcSeatId rowCol = (binarySearch row 0 0 127 'F' 'B') * 8 + (binarySearch col 0 0 7 'L' 'R')
  where
    row = fst rowCol
    col = snd rowCol

findAvailableSeat :: [Int] -> Int
findAvailableSeat xs = head $ filter (`notElem` xs) candidateSeats
  where
    candidateSeats       = map ((\a -> a - 1) . head) seatsDifferingByTwo
    seatsDifferingByTwo  = filter (\(a:b:_) -> (a - b) == 2) allPossibleSeatPairs
    allPossibleSeatPairs = [[a, b] | a <- xs, b <- xs, a /= b]

main :: IO ()
main = interact $ show . findAvailableSeat . map (calcSeatId . splitAt 7) . lines
