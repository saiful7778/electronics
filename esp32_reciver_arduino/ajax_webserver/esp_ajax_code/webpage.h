//============
//Webpage Code
//============
String webpageCode = R"***(
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>DTR-Home automation</title>
    <style>
      html {
        margin: 0;
        padding: 0;
        margin: auto;
        background: #222222;
      }
      .container {
        height: 90%;
        margin: auto;
        max-width: 90%;
        background: #121212;
        border-radius: 5px;
        padding: 30px;
      }
      #show_Data {
        display: flex;
        justify-content: center;
        align-items: center;
        background: #323232;
        height: 50px;
        max-width: 100%;
        border-radius: 5px;
        margin: auto;
      }
      #show_Status {
        color: #ffffff;
        font-weight: 500;
        font-family: Arial, Helvetica, sans-serif;
      }
      .status_style {
        color: #ff0000 !important;
      }
      .button_section {
        margin-top: 20px;
        max-width: 100%;
        display: grid;
        gap: 10px;
        grid-template-columns: repeat(4, 1fr);
      }
      .button_section div p {
        width: 100%;
        margin: 0;
        margin-bottom: 5px;
        height: 20px;
        color: #ffffff;
        font-family: Arial, Helvetica, sans-serif;
        font-weight: 500;
        font-size: 16px;
        text-align: center;
        text-transform: uppercase;
      }
      .button_section div button {
        width: 100%;
      }
      .btn {
        cursor: pointer;
        padding: 15px;
        border-radius: 5px;
        border: none;
        background: #424242;
        color: #ffffff;
        font-weight: 500;
        font-family: Arial, Helvetica, sans-serif;
        font-size: 15px;
      }
      .btn:hover {
        background: #525252;
      }
      @media all and (max-width: 900px) {
        .button_section {
          grid-template-columns: 1fr 1fr;
        }
      }
    </style>
  </head>
  <body>
    <div class="container">
      <div id="show_Data"><span id="show_Status">Car in garage</span></div>
      <div class="button_section">
        <div>
          <p id="btn-1-status">on</p>
          <button class="btn" id="btn-1">Switch 1</button>
        </div>
        <div>
          <p id="btn-2-status"></p>
          <button class="btn" id="btn-2">Switch 2</button>
        </div>
        <div>
          <p id="btn-3-status"></p>
          <button class="btn" id="btn-3">Switch 3</button>
        </div>
        <div>
          <p id="btn-4-status"></p>
          <button class="btn" id="btn-4">Switch 4</button>
        </div>
      </div>
    </div>
    <script>
      const buttonStatus = document.querySelectorAll(".button_section div p");
      const button = document.querySelectorAll(".button_section div button");
      for (let i = 0; i < button.length; i++) {
        button[i].addEventListener("click", () => {
          if (buttonStatus[i].innerHTML == "on") {
            buttonStatus[i].innerHTML = "off";
            buttonStatus[i].classList.add("status_style");
          } else {
            buttonStatus[i].innerHTML = "on";
            buttonStatus[i].classList.remove("status_style");
          }
        });
      }
    </script>
  </body>
</html>
)***";
