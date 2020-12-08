import qualified Data.HashSet as HS
import           Data.Maybe         (mapMaybe)

execute :: Int -> Int -> HS.HashSet Int -> [[String]] -> Int -> Maybe Int
execute idx acc visited xs replaceCmdAtWhichIdx
  | atLastInstruction    = if canFinish then Just newAcc else Nothing
  | cannotReplaceInstr   = Nothing
  | alreadyVisited       = Nothing
  | instruction == "acc" = execute (idx + 1       ) (acc + argument) newVisited xs replaceCmdAtWhichIdx
  | instruction == "jmp" = execute (idx + argument) (acc           ) newVisited xs replaceCmdAtWhichIdx
  | instruction == "nop" = execute (idx + 1       ) (acc           ) newVisited xs replaceCmdAtWhichIdx
  where
    atLastInstruction  = idx == length xs - 1
    cannotReplaceInstr = shouldReplaceInstruction && instructionTbd == "acc"
    alreadyVisited     = HS.member idx visited
    newVisited         = HS.insert idx visited
    newAcc
      | instruction == "acc" = acc + argument
      | otherwise            = acc
    canFinish
     | instruction == "acc"                   = True
     | instruction == "nop"                   = True
     | instruction == "jmp" && argsign == '+' = True
     | otherwise                              = False
    argument
      | argsign == '-' = argnum * (-1)
      | argsign == '+' = argnum
      | otherwise      = error ("invalid input (argsign) " ++ show argsign)
    argnum             = read $ tail argumentTbd :: Int
    argsign            = argumentTbd !! 0
    argumentTbd        = xs !! idx !! 1
    instruction
      | instructionTbd == "jmp" = if shouldReplaceInstruction then "nop" else "jmp"
      | instructionTbd == "nop" = if shouldReplaceInstruction then "jmp" else "nop"
      | instructionTbd == "acc" = "acc"
      | otherwise               = error ("invalid input (instructionTbd) " ++ show instructionTbd)
    instructionTbd           = xs !! idx !! 0
    shouldReplaceInstruction = idx == replaceCmdAtWhichIdx

findAccumWithoutCycle :: [[String]] -> Int
findAccumWithoutCycle xs = head $ mapMaybe executeOnce replacementIndexes
  where
    executeOnce        = execute 0 0 (HS.fromList []) xs
    replacementIndexes = filter (\idx -> idx == -1 || (xs !! idx !! 0) /= "acc") [-1..(length xs - 1)]

main :: IO ()
main = interact $ show . findAccumWithoutCycle . map words . lines
