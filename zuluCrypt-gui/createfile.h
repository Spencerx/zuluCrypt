/*
 *
 *  Copyright ( c ) 2011-2015
 *  name : Francis Banyikwa
 *  email: mhogomchungu@gmail.com
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  ( at your option ) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CREATEFILE_H
#define CREATEFILE_H

#include <QDialog>

#include "utility.h"

class DialogMsg ;
class QPushButton ;
class FileTask ;
class QCloseEvent ;
class createfile ;

namespace Ui {
    class createfile ;
}

class createfile : public QDialog
{
	Q_OBJECT
public:
	static createfile& instance( QWidget * parent,std::function< void( const QString& ) > f )
	{
		return *( new createfile( parent,std::move( f ) ) ) ;
	}
	explicit createfile( QWidget *,std::function< void( const QString& ) > ) ;
	~createfile() ;
signals :
	void sendProgress( QString,QString,QString,QString,int ) ;
private:
	void warnAboutRandomData( bool ) ;
	void HideUI() ;
	void showUI() ;
	void pbOpenFolder() ;
	void pbCancel() ;
	void pbCreate() ;
	void setProgress( QString,QString,QString,QString,int ) ;
	void fileTextChange( QString ) ;
	void createFile( const QString&,qint64 ) ;
	void enableAll() ;
	void disableAll() ;
	void closeEvent( QCloseEvent * ) ;
	bool eventFilter( QObject * watched,QEvent * event ) ;
	Ui::createfile * m_ui ;
	std::atomic_bool m_exit ;
	bool m_running ;
	std::function< void( const QString& ) > m_function ;
	utility::label m_label ;
};

#endif // CREATEFILE_H
