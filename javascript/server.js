require('dotenv').config();
const express = require('express');
const mongoose = require('mongoose');
const cookieParser = require('cookie-parser');
const cors = require('cors');
const path = require('path');

const app = express();
const PORT = process.env.PORT || 3001;

app.use(cors());
app.use(express.json());
app.use(cookieParser());
app.use(express.static('public'));

mongoose.connect(process.env.MONGODB_URI || 'mongodb://localhost:27017/visitor-counter', {
    useNewUrlParser: true,
    useUnifiedTopology: true
})
.then(() => {
    console.log('Connected to MongoDB successfully');
    console.log('Database URL:', process.env.MONGODB_URI || 'mongodb://localhost:27017/visitor-counter');
})
.catch(err => {
    console.error('MongoDB connection error:', err);
    console.error('Please make sure MongoDB is running and accessible');
});

const visitorSchema = new mongoose.Schema({
    visitorId: { type: String, unique: true },
    ip: String,
    userAgent: String,
    timestamp: { type: Date, default: Date.now },
    lastVisit: { type: Date, default: Date.now }
});

const Visitor = mongoose.model('Visitor', visitorSchema);

app.get('/api/visitors/count', async (req, res) => {
    try {
        const count = await Visitor.countDocuments();
        res.json({ count });
    } catch (error) {
        res.status(500).json({ error: 'Error fetching visitor count' });
    }
});

app.post('/api/visitors/track', async (req, res) => {
    try {
        const ip = req.ip;
        const userAgent = req.headers['user-agent'];
        const timestamp = new Date().getTime();
        // Create a more unique visitor ID that includes timestamp
        const visitorId = `${ip}-${userAgent}-${timestamp}`;
        
        console.log(`Tracking visitor - IP: ${ip}, User-Agent: ${userAgent}`);
        
        // Create new visitor record
        console.log('Creating new visitor record');
        const visitor = new Visitor({ 
            visitorId,
            ip, 
            userAgent 
        });
        await visitor.save();
        
        const count = await Visitor.countDocuments();
        console.log(`Total visitor count: ${count}`);
        res.json({ count });
    } catch (error) {
        console.error('Error tracking visitor:', error);
        res.status(500).json({ error: 'Error tracking visitor: ' + error.message });
    }
});

// Serve the main page
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'public', 'index.html'));
});

app.listen(PORT, () => {
    console.log(`Server running on port ${PORT}`);
}); 
