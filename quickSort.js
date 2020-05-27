const quickSort = function (array) {
  if (array.length <= 1) {
    return array;
  }

  const pivot = [array[array.length - 1]];
  const smallerElements = array.filter((num) => num < pivot[0]);
  const largerElements = array.filter((num) => num > pivot[0]);
  return [quickSort(smallerElements), pivot, quickSort(largerElements)].flat();
};

const main = function () {
  const unsortedArray = [18, 35, 24, 6, 23, 12, 39, 67];
  console.log(quickSort(unsortedArray));
};

main();
