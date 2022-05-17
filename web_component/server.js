const express = require('express');
const path = require('path');
const bodyParser = require('body-parser');

const app = express();
const port = process.env.PORT || 3001;

app.set('views', __dirname + '/views');
app.set('view engine', 'ejs');

app.use(bodyParser.urlencoded({ extended: true }));

app.use(express.static(path.join(__dirname, './static')));

app.get('/', (req, res) => {
  res.render('index');
});

app.get('/new-item', (req, res) => {
  res.render('new-item');
});

app.post("/new-item", (req, res) => {
  var title = Number(req.body.title);
  var date = Number(req.body.date);
  var description = Number(req.body.description);
  res.redirect("/");
});

app.listen(port);

console.log(`Listening on port ${port}` + "  http://localhost:" + port);
