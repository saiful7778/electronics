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
      body{
        background: #222222;;
      }
      *{
        margin: 0;
        padding: 0;
      }
      .container {
        margin: 10px auto;
        width: 80%;
        background: #121212;
        border-radius: 5px;
        padding: 30px;
      }
      .logo_section{
        text-align: center;
        margin-bottom: 20px;
        display: flex;
        justify-content: center;
      }
      .text{
        color: #ffffff;
        font-family: Arial, Helvetica, sans-serif;
        font-size: 14px;
      }
      .text h1{
        margin-left: 10px;
        margin-top: 8px;
      }
      .text p{
        text-align: right;
        font-family: Arial, Helvetica, sans-serif;
        font-weight: 300;
        font-size: 11px;
        color: #a0a0a0;
      }
      svg{
        width: 50px;
        height: 50px;
      }
      #show_Data {
        display: flex;
        justify-content: center;
        align-items: center;
        background: #323232;
        height: 50px;
        width: 100%;
        border-radius: 5px;
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
        width: 100%;
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
        .text p{
          font-size: 8px;
        }
        h1{
          font-size: 14px;
        }
        .button_section {
          grid-template-columns: 1fr 1fr;
        }
      }
    </style>
  </head>
  <body>
    <div class="container">
      <div class="logo_section">
        <svg
          version="1.2"
          xmlns="http://www.w3.org/2000/svg"
          viewBox="0 0 200 200"
          width="50"
          height="50"
        >
          <defs>
            <image
              width="194"
              height="195"
              id="img1"
              href="data:image/png;base64,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"
            />
          </defs>
          <style></style>
          <use href="#img1" x="3" y="3" />
        </svg><div class="text"><h1>DTR - Home automation</h1><p>created by Saiful Islam</p></div>
      </div>
      <div id="show_Data"><span id="show_Status"></span></div>
      <div class="button_section">
        <div>
          <p id="btn-1-status"></p>
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
