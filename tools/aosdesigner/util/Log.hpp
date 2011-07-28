#ifndef HGUARD_AOSD_UTIL_LOG_HPP__
#define HGUARD_AOSD_UTIL_LOG_HPP__
#pragma once

// beuh...
#include <sstream>
#include <QString>


/* Logging macros :

   AOSD_LOG << "Hello World? " << 42 ; // log a message 
   AOSD_LOG_ERROR << "SOMETHING IS WRONG!" << 666 ; // log an error
   AOSD_LOG_DEBUG << "About this value ..." << iterator << ", did you know?" ; // log debug informations
*/

#ifdef _DEBUG // TODO : replace that by something assured to be cross-platform...
#define AOSD_DEBUG_LOG_ON 1
#else
#define AOSD_DEBUG_LOG_ON 0
#endif

#define AOSD_LOG_WITH_LEVEL( log_level )	aosd::util::Log( log_level )
#define AOSD_LOG			AOSD_LOG_WITH_LEVEL( aosd::util::Log::INFO )
#define AOSD_LOG_ERROR		AOSD_LOG_WITH_LEVEL( aosd::util::Log::ERROR )

#define AOSD_LOG_NOTHING   if(false) aosd::util::NoLog() 


#if AOSD_DEBUG_LOG_ON == 1
#define AOSD_LOG_DEBUG		AOSD_LOG_WITH_LEVEL( aosd::util::Log::DEBUG )
#else 
#define AOSD_LOG_DEBUG AOSD_LOG_NOTHING
#endif

namespace aosd
{
namespace util
{
	/** NO DOCUMENTATION YET!
	*/
	class Log
	{
	public:

		enum Level
		{
			ERROR
		,	INFO
		,	DEBUG
		};

		static const char* name( Level level );

		Log( Level level );
		~Log();

		template< typename T >
		Log& operator<<( const T& message )
		{
			m_stream << message;
			return *this;
		}

		template<>
		Log& operator<< <QString> ( QString const & message )
		{
			m_stream << message.toStdString();
			return *this;
		}

	private:
		
		Level m_level;
		std::stringstream m_stream;

		void log();

	};

	class NoLog
	{
	public:
		template< typename T >
		void operator<<( const T& message )
		{ }
	};


}
}


#endif