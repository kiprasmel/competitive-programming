countTrees :: Int -> [[Char]] -> Int
countTrees i xs
  | rowIdx >= length xs = 0
  | otherwise           = isTree + (countTrees (i + 1) xs)
  where
    isTree    = if currPos == '#' then 1 else 0
    currPos   = (xs !! rowIdx) !! modColIdx
    rowIdx    =  i
    modColIdx = (i * 3) `mod` (length (xs !! 0))

main :: IO ()
main = interact $ show . countTrees 1 . lines

