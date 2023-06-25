let arr = [0, 1, 0, 3, 12];
let size = arr.length;
let index = 0;

for (let i = 0; i < size; i++) {
  if (arr[i] !== 0) {
    arr[index++] = arr[i];
  }
}

for (let i = index; i < size; i++) {
  arr[i] = 0;
}

console.log("elements - " + arr.join("  "));
