const express = require("express")
const bodyParser = reqiure("body-parser")

const PORT = process.env.PORT || 3004

const setupAndStartServer = async() =>{
    const app = express()
    app.use(bodyParser.json())
    app.use(bodyParser.urlencoded({extended: true}))

    app.get("/", (req,res)=>{
        res.status(200).json({
            success: true,
            message: "Server is running"
        })
    })
    app.put("/api/users/:id", (req, res)=>{
        const userId= parseInt(req.params)
        const {name} = req.body;

        const user = users.find((u)=>u.id ===userId)
        if(!user){

        }
        user.name = name
    })

}