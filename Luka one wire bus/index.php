<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <link rel="stylesheet" type="text/css" href="css/table.css">
</head>

<body>
  <h1>Podatki mikro klime</h1>
  <p> Podatki temperature in vlage v slamnati hiši</p>
</body>

</html>
<?php

$servername = "localhost";
$username = "root";
$password = "slovenskasmer";
$dbname = "db1";


// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
};

$sql = "SELECT * FROM db1.klima";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    echo "<table>";
    echo "<table><tr><th>T1</th><th>T2</th><th>H1</th><th>H1_t</th></tr>";
    // output data of each row
    while($row = $result->fetch_assoc()) {
        echo "<tr><td>".$row["T1"]."</td><td>".$row["T2"]."</td><td>".$row["H1"]."</td><td>".$row["H1_t"]."</td></tr>";
    }
    echo "</table>";
} else {
    echo "0 results";
}

$conn->close();
?>
