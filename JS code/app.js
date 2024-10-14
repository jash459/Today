// Import express and body-parser
const express = require("express");
const bodyParser = require("body-parser");

// Define the port
const PORT = process.env.PORT || 3000;

// Function to set up and start the server
const setupAndStartServer = async () => {
    // Create the express object
    const app = express();

    // Use body-parser middleware to parse JSON and URL-encoded bodies
    app.use(bodyParser.json());
    app.use(bodyParser.urlencoded({ extended: true }));

    // In-memory database for simplicity
    let users = [
        { id: 1, name: "John Doe" },
        { id: 2, name: "Jane Doe" }
    ];

    // Simple route to check if the server is running
    // http://localhost:3000/
    app.get('/', (req, res) => {
        res.status(200).json({
            success: true,
            message: 'Welcome to the Simple Express API!'
        });
    });

    // GET API to fetch all users
    // http://localhost:3000/api/users
    app.get('/api/users', (req, res) => {
        res.status(200).json({
            success: true,
            data: users
        });
    });

    // POST API to create a new user
    // http://localhost:3000/api/users
    app.post('/api/users', (req, res) => {
        const { name } = req.body;

        if (!name) {
            return res.status(400).json({
                success: false,
                message: 'Name is required'
            });
        }

        const newUser = {
            id: users.length + 1, // Simulate unique ID
            name: name
        };

        users.push(newUser);

        res.status(201).json({
            success: true,
            message: 'User created successfully',
            data: newUser
        });
    });

    // PUT API to update a user by ID
    // http://localhost:3000/api/users/1
    app.put('/api/users/:id', (req, res) => {
        const userId = parseInt(req.params.id);
        const { name } = req.body;

        const user = users.find(u => u.id === userId);

        if (!user) {
            return res.status(404).json({
                success: false,
                message: 'User not found'
            });
        }

        if (!name) {
            return res.status(400).json({
                success: false,
                message: 'Name is required'
            });
        }

        user.name = name;

        res.status(200).json({
            success: true,
            message: 'User updated successfully',
            data: user
        });
    });

    // DELETE API to delete a user by ID
    // http://localhost:3000/api/users/1
    app.delete('/api/users/:id', (req, res) => {
        const userId = parseInt(req.params.id);

        const userIndex = users.findIndex(u => u.id === userId);

        if (userIndex === -1) {
            return res.status(404).json({
                success: false,
                message: 'User not found'
            });
        }

        const deletedUser = users.splice(userIndex, 1);

        res.status(200).json({
            success: true,
            message: 'User deleted successfully',
            data: deletedUser[0]
        });
    });

    // Start the server
    app.listen(PORT, async () => {
        console.log(`Server is running on port ${PORT}`);
    });
};

// Call the setupAndStartServer function to start the server
setupAndStartServer();
