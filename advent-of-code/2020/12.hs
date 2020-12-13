{- -2 -1 0 +1 +2 -]
-2
-1       N
 0     W   E
+1       S
+2
[-               -}

type Direction = Char

directions :: [Direction]
directions = ['E', 'S', 'W', 'N']  -- from 0 to 360 degrees; each index is a step of 90 degrees

type Rotation = Char

rotations :: [Rotation]
rotations = ['L', 'R']

type RotationDegree = Int

getDirectionFromDegree :: RotationDegree -> Direction
getDirectionFromDegree rotationDegree = newDir
  where
    newDir   = directions !! dirIndex
    dirIndex = (rotationDegree `mod` 360) `div` 90

type Pos = (Int, Int)
type Instruction = String

travel :: Pos -> RotationDegree -> [Instruction] -> Pos
travel (x, y) degree [] = (x, y)
travel (x, y) degree xs = travel (newX, newY) newDegree remainingInstructions
  where
    newX
      | action `elem` rotations = x
      | dir == 'E'              = x + amount
      | dir == 'W'              = x - amount
      | otherwise               = x

    newY
      | action `elem` rotations = y
      | dir == 'S'              = y + amount
      | dir == 'N'              = y - amount
      | otherwise               = y

    dir
      | action `elem` rotations  = '-'  -- won't use
      | action `elem` directions = action
      | action == 'F'            = getDirectionFromDegree degree
      | otherwise                = error ("invalid action " ++ show action)

    newDegree
      -- | action `elem` rotations = degree + amount  --  <-- don't do this lol (R stands for [R]ight, not [R]otate lmao)
      | action == 'L' = degree - amount
      | action == 'R' = degree + amount
      | otherwise     = degree

    amount = read (tail instruction) :: Int
    action =       head instruction

    remainingInstructions = tail xs
    instruction           = head xs

calcManhattan :: Pos -> Pos -> Int
calcManhattan (xA, yA) (xB, yB) = abs (xA - xB) + abs (yA - yB)

solve = (++ "\n") . show . calcManhattan startingPos . travel startingPos startingDegree . words
  where
    startingPos    = (0, 0)
    startingDegree = 0

main :: IO ()
main = interact $ solve
