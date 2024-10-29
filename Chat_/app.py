from flask import Flask, render_template
from flask_socketio import SocketIO, send

app = Flask(__name__)
app.config['SECRET_KEY'] = 'mysecret'
socketio = SocketIO(app)

# Ruta para la página principal del chat
@app.route('/')
def index():
    return render_template('chat.html')

# Maneja los mensajes enviados a través del WebSocket
@socketio.on('message')
def handleMessage(msg):
    print('Mensaje recibido: ' + msg)
    send(msg, broadcast=True)  # Enviar el mensaje a todos los clientes conectados
    return None

if __name__ == '__main__':
    socketio.run(app)
