// MiniChat.cpp: definisce il punto di ingresso dell'applicazione.
//

#include "MiniChat.h"

#include <vector>
#include <functional>
#include <string>
using namespace std;

#include <boost/asio.hpp>

namespace asio = boost::asio;
using tcp = asio::ip::tcp;
using error = boost::system::error_code;


int main()
{

	vector<tcp::socket> clients{};
	asio::io_context context;
	tcp::socket socket(context);
	tcp::endpoint endpoint(tcp::v4(), 1234);
	tcp::acceptor acceptor(context, endpoint);

	function<void(error)> accept_handler = [&](error ec) {
		
		if (!ec) {

			tcp::socket client = std::move(socket);

			cout << "Accepting " << client.remote_endpoint() << endl;

			string ss{ "Connected to " };

			ss +=  client.remote_endpoint().address().to_string() += client.remote_endpoint().port();

			client.write_some(asio::buffer(ss));

			clients.push_back(std::move(client));

			socket = tcp::socket(context);
			acceptor.async_accept(socket, accept_handler);
		}

	};

	acceptor.async_accept(socket, accept_handler);

	cout << "Starting Server" << endl;
	context.run();

	return 0;
}
