import qualified Data.HashSet as HS

execute :: Int -> Int -> HS.HashSet Int -> [[String]] -> Int
execute idx acc visited xs
  | HS.member idx visited = acc
  | instruction == "acc"  = execute (idx + 1)        (acc + argument) newVisited xs
  | instruction == "jmp"  = execute (idx + argument) (acc           ) newVisited xs
  | instruction == "nop"  = execute (idx + 1)        (acc           ) newVisited xs
  where
    newVisited  = HS.insert idx visited
    argument
      | argsign == '-' = argnum * (-1)
      | otherwise      = argnum
    argnum      = read $ tail argumentTbd :: Int
    argsign     = argumentTbd !! 0
    argumentTbd = xs !! idx !! 1
    instruction = xs !! idx !! 0

main :: IO ()
main = interact $ show . execute 0 0 (HS.fromList []) . map words . lines
