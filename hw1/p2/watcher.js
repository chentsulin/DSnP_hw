const { exec } = require('child_process');
const chokidar = require('chokidar');

chokidar.watch(['*.cpp', '*.h', '*.csv']).on('all', (event, path) => {
  exec('make', (err) => {
    if (err) {
      return console.error(err);
    }
    exec('./p2Run');
  });
});
