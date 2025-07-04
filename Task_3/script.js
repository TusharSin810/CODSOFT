const display = document.getElementById('display');
const buttons = document.querySelectorAll('.btn');

let currentInput = '';
let resultDisplayed = false;

buttons.forEach(button => {
  button.addEventListener('click', () => {
    const value = button.getAttribute('data-value');

    if (value) {
      if (resultDisplayed) {
        currentInput = '';
        resultDisplayed = false;
      }
      currentInput += value;
      display.value = currentInput;
    }
  });
});

document.getElementById('clear').addEventListener('click', () => {
  currentInput = '';
  display.value = '';
});

document.getElementById('equals').addEventListener('click', () => {
  try {
    currentInput = eval(currentInput).toString();
    display.value = currentInput;
    resultDisplayed = true;
  } catch (e) {
    display.value = 'Error';
    currentInput = '';
  }
});
