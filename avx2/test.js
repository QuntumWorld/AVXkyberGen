const { exec } = require('child_process');

function executeCommand(command) {
  return new Promise((resolve, reject) => {
    exec(command, (error, stdout, stderr) => {
      if (error) {
        reject(error);
      } else {
        resolve(stdout);
      }
    });
  });
}

let keypair;

executeCommand('./example')
  .then((stdout) => {
    keypair = stdout.split('@@');
    publickey =Buffer.from(keypair[0],'hex')
    privatekey= Buffer.from(keypair[1],'hex')
    console.log("publickey: ", publickey);
    console.log("privatkey: ",privatekey);
  })
  .catch((error) => {
    console.log(error);
  });
