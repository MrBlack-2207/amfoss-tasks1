function isPrime(num) {
    if (num < 2) return false;
    if (num === 2 || num === 3) return true;
    if (num % 2 === 0 || num % 3 === 0) return false;
  
    let i = 5;
    while (i * i <= num) {
      if (num % i === 0 || num % (i + 2) === 0) return false;
      i += 6;
    }
  
    return true;
  }
  
  function getInput() {
    let k = 0;
    process.argv.forEach((val, index) => {
      if (index === 2) {
        k = parseInt(val);
      }
    });
    return k;
  }
  
  function printPrimes(n) {
    for (let i = 2; i <= n; i++) {
      if (isPrime(i)) console.log(i);
    }
  }
  
  const k = getInput();
  printPrimes(k);
