import Data.List.Split (divvy)

createGroupsOf26WithOffsetOf1 :: [Int] -> [[Int]]
createGroupsOf26WithOffsetOf1 = divvy 26 1

isValid :: [Int] -> Bool
isValid revXs = canFormSum
  where
    canFormSum       = (>0) $ length [True | a <- availableChoices, b <- availableChoices, a + b == targetSum && a /= b]
    availableChoices = tail revXs
    targetSum        = head revXs

findViolation :: [[Int]] -> Int
findViolation deepRevXs = violatedValue
  where
    violatedValue      = head firstViolatedGroup  -- `head` instead of `last`
                                                  -- because each group is reversed
                                                  -- for better perf & correctness
    firstViolatedGroup = head $ filter (not . isValid) deepRevXs

main :: IO ()
main = interact $ (++ "\n") . show . findViolation . map reverse . createGroupsOf26WithOffsetOf1 . map read . lines
