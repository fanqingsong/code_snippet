requirejs.config({
    //By default load any module IDs from ./
    baseUrl: './',
});

// Start the main app logic.
requirejs(['one', 'two'],
function   (one, two) {
    one();
    two();
});