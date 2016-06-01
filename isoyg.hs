import System.Environment
import Data.List
import Data.List.Split  -- Type 'cabal install split'

isoyg :: String -> [String]
isoyg s = endBy "your grave" s

splitAll :: [String] -> [[String]]
splitAll args = map isoyg args

splitAndJoin :: [String] -> String
splitAndJoin args =
  let merge lns = foldr (\i r -> i ++ "\n" ++ r) "" lns
      args2 = map merge $ splitAll args
  in merge args2

main = do
  args <- getArgs
  putStr $ splitAndJoin args
  
