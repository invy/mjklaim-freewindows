#ifndef HGUARD_AOSD_CORE_EDITIONSESSION_HPP__
#define HGUARD_AOSD_CORE_EDITIONSESSION_HPP__
#pragma once


#include <boost/filesystem/path.hpp>
#include <QObject>

#include "core/EditionSessionId.hpp"
#include "aoslcpp/SequenceInterpreter.hpp"


namespace aosd
{
namespace core
{
	class Project;
	class Sequence;
	

	namespace bfs = boost::filesystem;

	/** Informations about an edition session of a sequence.
	*/
	class EditionSession
		: public QObject
	{
		Q_OBJECT
	public:

		/** Constructor : create a new edition session.
			@param project		Project in which this edition session occurs.
			@param sequence		Sequence that is being walked in.
			@param name			Name of the session, displayed in views.
		**/
		EditionSession( const Project& project, const Sequence& sequence, const std::string& name );

		/**	Constructor : load a edition session from a file.
			@param project		Project in which this session occurs.
			@param file_path	Path of the file containing the session informations.
		**/
		EditionSession( const Project& project, const bfs::path& file_path );
	
		const EditionSessionId& id() const { return m_id; }

		const std::string& name() const { return m_name; }

		bool is_valid() const { return m_sequence && m_interpreter; }
		
	public slots:

		void save();

	signals:

		
	private slots:


	private:

		std::unique_ptr<aoslcpp::SequenceInterpreter> m_interpreter;

		std::string m_name;


		const Project& m_project;
		const Sequence* m_sequence;

		EditionSessionId m_id;

	};


}
}


#endif