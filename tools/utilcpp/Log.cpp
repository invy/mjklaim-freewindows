#include "Log.hpp"

#include <exception>

#include <boost/format.hpp>
#include <boost/date_time.hpp>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

#ifdef _WIN32

	#ifndef WIN32_LEAN_AND_MEAN
	#define WIN32_LEAN_AND_MEAN
	#endif

	#include <windows.h>

	namespace 
	{
		const bool IS_VS_DEBUGGER_PRESENT = IsDebuggerPresent() != FALSE; // to avoid warnings
	}

	#ifdef ERROR // WTF???
		#undef ERROR
	#endif

#endif

#include "Singleton.hpp"




namespace util
{
	namespace
	{
		const boost::filesystem::path LOG_FILE_DIR = "./logs";

		class LogFileHandler 
		{
		public:
			LogFileHandler()
				: m_stream( generate_log_file_path().string() )
			{
				
			}

			void log( const std::string& message )
			{
				m_stream << message  << std::endl;
			}

		private:

			boost::filesystem::ofstream m_stream;


			static boost::filesystem::path generate_log_file_path()
			{
				const auto now = boost::posix_time::second_clock::local_time();
				const auto date = now.date();
				const auto time = now.time_of_day();

				// TODO : move the format in the path header?
				const auto filename = boost::format( "%1$04i%2$02i%3$02i_%4$02i%5$02i%6$02i.log" ) % date.year() % int(date.month()) % date.day() % time.hours() % time.minutes() % time.seconds();

				if( !boost::filesystem::exists( LOG_FILE_DIR ) )
				{
					boost::filesystem::create_directories( LOG_FILE_DIR );
				}

				return LOG_FILE_DIR / boost::filesystem::path( filename.str() );
			}

		};

		LogFileHandler log_file_handler;

	}

	Log::Log( Level level )
		: m_level( level )
	{
		const auto now = boost::posix_time::second_clock::local_time();
		const auto date = now.date();
		const auto time = now.time_of_day();

		const auto formated = boost::format( "[%1$04i.%2$02i.%3$02i.%4$02i:%5$02i:%6$02i][%7$-5s] " ) 
										% date.year() % int(date.month()) % date.day() % time.hours() % time.minutes() % time.seconds() % name(m_level);

		m_stream << formated;
	}

	Log::~Log()
	{
		log();
	}

	void Log::log()
	{
		// this is a naive unsafe and non-thread-safe implementation
		// but it should work well for a start

		const auto message =  m_stream.str();

		// first we log into the file
		log_file_handler.log( message );

		// next we log into the "standard" outputs
		// log into Visual Studio if we are debugging in it
#if defined( _DEBUG ) && defined( _WIN32 ) // TODO : replace this by something more safe...
		if( IS_VS_DEBUGGER_PRESENT ) 
			OutputDebugString( (message + "\n").c_str() ); 
#endif
		switch ( m_level )
		{
		case( Log::ERROR ):
			std::cerr << message << '\n';
			break;
		case( Log::INFO ):
		case( Log::DEBUG ):
			std::cout << message << '\n';			
			break;

		default:
			throw std::runtime_error( "ERROR : Unknown logging level!" ); // TODO : replace this exception by custom ones?
		}

		

		// now we can display to the logging into the log view

	}

	const char* Log::name( Level level )
	{
		switch ( level )
		{
		case( Log::ERROR ):
			return "ERROR";
		case( Log::INFO ):
			return "INFO";
		case( Log::DEBUG ):
			return "DEBUG";
		
		default:
			return nullptr;
		}
	}

	


	
}