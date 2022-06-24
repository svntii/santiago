#!/usr/bin/env python3

import tornado.ioloop
import tornado.options
import tornado.web

PORT = 9999

# Handlers

class HelloHandler(tornado.web.RequestHandler):

    def get(self):
        name = self.get_argument('name', '')
        
        if name:
            self.write(f'<b>Hello, {name}</b>')

        self.write('''
        <h1>Hello, world </h1>

        <img src ='https://media.4-paws.org/9/8/9/0/989062cbadf1434ca133048fcac6ee403dbf09b6/VIER%20PFOTEN_2015-04-27_010-2000x1046-1200x628.jpg'>

'''        )

class FormHandler(tornado.web.RequestHandler):
    def get(self):
        self.write('''
        
    <h2> Enter your name </h2>
    <form> 
        <input type ="text" name="name" value="">
        <input type ="submit" value="Echo!">
    </form>

                ''')


def main():
    application = tornado.web.Application([
            (r'/', HelloHandler)

        ])
    application.listen(PORT)

    tornado.options.parse_command_line()
    tornado.ioloop.IOLoop.current().start()



if __name__ == '__main__':
    main()
