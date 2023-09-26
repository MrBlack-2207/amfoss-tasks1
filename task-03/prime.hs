isPrime :: Int -> Bool
isPrime num
  | num < 2 = False
  | num == 2 || num == 3 = True
  | num `mod` 2 == 0 || num `mod` 3 == 0 = False
  | otherwise = checkPrime 5
  where
    checkPrime i
      | i * i <= num = num `mod` i /= 0 && num `mod` (i + 2) /= 0 && checkPrime (i + 6)
      | otherwise = True

getInput :: IO Int
getInput = do
  putStr "Type a number: "
  input <- getLine
  let k = read input :: Int
  if k >= 2 then
    return k
  else
    getInput

printPrimes :: Int -> IO ()
printPrimes n = mapM_ (\x -> putStrLn (show x)) (filter isPrime [2..n])

main :: IO ()
main = do
  k <- getInput
  printPrimes k
