const express = require('express');
const fs = require('fs');
const cors = require('cors');
const { exec } = require('child_process');
const path = require('path');

const app = express();
app.use(cors());
app.use(express.json());

app.post('/simulate', (req, res) => {
    const { processes, algorithm } = req.body;  // Fixed: processes (array)

    console.log('Received data:', { processes, algorithm });

    // Validate input
    if (!processes || !Array.isArray(processes) || processes.length === 0) {
        return res.status(400).json({ error: "Invalid processes data" });
    }

    if (!algorithm) {
        return res.status(400).json({ error: "Algorithm not specified" });
    }

    try {
        // Save input to JSON file
        const inputData = { processes, algorithm };
        const inputPath = path.join(__dirname, 'web', 'input.json');
        
        fs.writeFileSync(inputPath, JSON.stringify(inputData, null, 2));
        console.log('Input saved to:', inputPath);

        // Execute C++ program
        const exePath = path.join(__dirname, 'scheduler.exe');
        
        exec(`"${exePath}"`, { cwd: __dirname }, (error, stdout, stderr) => {
            if (error) {
                console.error("Execution Error:", error);
                console.error("stderr:", stderr);
                return res.status(500).json({ 
                    error: "Execution failed", 
                    details: stderr || error.message 
                });
            }

            console.log("C++ stdout:", stdout);

            try {
                // Read output file
                const outputPath = path.join(__dirname, 'web', 'output.json');
                
                if (!fs.existsSync(outputPath)) {
                    return res.status(500).json({ error: "Output file not generated" });
                }

                const output = JSON.parse(fs.readFileSync(outputPath, 'utf8'));
                console.log('Sending output:', output);
                
                res.json({
                    success: true,
                    results: output,
                    algorithm: algorithm
                });

            } catch (parseError) {
                console.error("JSON Parse Error:", parseError);
                res.status(500).json({ 
                    error: "Failed to parse output", 
                    details: parseError.message 
                });
            }
        });

    } catch (err) {
        console.error("Server Error:", err);
        res.status(500).json({ 
            error: "Server error", 
            details: err.message 
        });
    }
});

app.listen(3000, () => {
    console.log('Server is running on port 3000');
    console.log('Make sure scheduler.exe is in the same directory as server.js');
});