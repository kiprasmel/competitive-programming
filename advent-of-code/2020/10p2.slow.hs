import Data.List (sort)

wrap :: [Int] -> [Int]
wrap sortedXs = [0] ++ sortedXs ++ [last sortedXs + 3]

isAllowed :: [Int] -> Int -> Int -> Bool
isAllowed xs currIdx newIdx = newIdx >= 0 && diff <= 3
  where
    diff   = currEl - newEl
    newEl  = xs !! newIdx
    currEl = xs !! currIdx

-- dp[position] = how many ways to get to this position
dp :: [Int] -> Int -> Int
dp xs idx
  | idx <= 0         = 1
  | idx >= length xs = error ("idx too big " ++ show idx)
  | otherwise        = sum dpResultsFromAllowedIndexes
  where
    dpResultsFromAllowedIndexes = map (dp xs) allowedIndexes
    allowedIndexes              = filter (isAllowed xs idx) backwardIndexes
    backwardIndexes             = [(idx - 3)..(idx - 1)]

dp' :: [Int] -> Int
dp' xs = dp xs (length xs - 1)

main :: IO ()
main = interact $ (++ "\n") . show . dp' . wrap . sort . map read . lines
