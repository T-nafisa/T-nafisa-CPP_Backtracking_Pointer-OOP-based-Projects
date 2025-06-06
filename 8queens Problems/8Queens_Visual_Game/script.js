async function loadBoard() {
    const board = document.getElementById("board");
    board.innerHTML = ""; // Clear board

    try {
        const response = await fetch("solution.txt");
        const text = await response.text();
        console.log("Loaded solution.txt:", text);  // 🔍 DEBUG LINE
        const positions = text.trim().split(" ").map(Number);

        for (let row = 0; row < 8; row++) {
            for (let col = 0; col < 8; col++) {
                const square = document.createElement("div");
                square.classList.add("square");
                square.classList.add((row + col) % 2 === 0 ? "white" : "black");

                if (positions[col] === row) {
                    square.textContent = "♛";
                }

                board.appendChild(square);
            }
        }
    } catch (err) {
        console.error("ERROR loading solution.txt:", err);
        alert("Could not load solution.txt. Run your C++ program first!");
    }
}
