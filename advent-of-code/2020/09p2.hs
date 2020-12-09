import Data.List       (sort)
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

createPrefixSums :: Int -> Int -> [Int] -> [Int]
createPrefixSums idx prev xs
  | idx <= length xs = curr : (createPrefixSums (idx + 1) curr xs)
  | otherwise        = []
  where
    curr
      | idx == 0  = 0
      | otherwise = (xs !! (idx - 1)) + prev

createPrefixSums' :: [Int] -> [Int]
createPrefixSums' = createPrefixSums 0 0

findRangeThatEqualsTarget :: Int -> Int -> [Int] -> Int -> (Int, Int)
findRangeThatEqualsTarget left right xs targetSum
  | left > right                             = findRangeThatEqualsTarget (right   ) (left     ) xs targetSum  -- swap
  | left == length xs || right == length xs  = (-1, -1)                                                       -- done; not found
  | currSum == targetSum && rangeLength >= 2 = (left - 1, right)                                              -- done;     found
  | currSum >  targetSum                     = findRangeThatEqualsTarget (left + 1) (right    ) xs targetSum
  | currSum <  targetSum                     = findRangeThatEqualsTarget (left    ) (right + 1) xs targetSum
  where
    rangeLength = right - left + 1
    currSum     = (xs !! right) - (xs !! (left - 1))

findRangeThatEqualsTarget' :: [Int] -> Int -> (Int, Int)
findRangeThatEqualsTarget' = findRangeThatEqualsTarget 1 1

solve :: [Int] -> Int
solve xs
  | left == -1 || right == -1 = error "impossible"
  | otherwise                 = smallestElement + biggestElement
  where
    smallestElement       = head elementsInRange
    biggestElement        = last elementsInRange
    elementsInRange       = sort . take (right - left + 1) . drop (left - 1) $ xs
    (left, right)         = findRangeThatEqualsTarget' prefixSums invalidNumFromPartOne
    prefixSums            = createPrefixSums' xs
    invalidNumFromPartOne = findViolation . map reverse . createGroupsOf26WithOffsetOf1 $ xs

main :: IO ()
main = interact $ (++ "\n") . show . solve . map read . lines
