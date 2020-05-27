const swap = (array, a, b) => ([array[a], array[b]] = [array[b], array[a]]);

const partition = function (array, start, end) {
  let pivot = array[start];
  pivot_index = start;

  for (let index = start; index < end; index++) {
    if (array[index] < pivot) {
      pivot_index++;
      swap(array, pivot_index, index);
    }
  }
  swap(array, start, pivot_index);

  return pivot_index;
};

const quickSort = function (array, start = 0, end = array.length) {
  if (start >= end) {
    return array;
  }

  const pivotIndex = partition(array, start, end);
  quickSort(array, start, pivotIndex);
  quickSort(array, pivotIndex + 1, end);
  return array;
};

const main = function () {
  const unsortedArray = [18, 35, 24345, 6, 23, 12, 39, 67];
  console.log(quickSort(unsortedArray));
};

main();

//------------------------------------------------------Another way---------------------------------------------

// const quickSort = function (array) {
//   if (array.length <= 1) {
//     return array;
//   }

//   const pivot = array[array.length - 1];
//   const smallerElements = array.filter((num) => num < pivot);
//   const largerElements = array.filter((num) => num > pivot);
//   return [quickSort(smallerElements), pivot, quickSort(largerElements)].flat();
// };

// const main = function () {
//   const unsortedArray = [18, 35, 24, 6, 23, 12, 39, 67];
//   console.log(quickSort(unsortedArray));
// };

// main();
